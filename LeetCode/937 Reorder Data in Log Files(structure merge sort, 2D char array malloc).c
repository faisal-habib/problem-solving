/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct
{
    int index;
    char identifier[103], logWords[103];
}DataInfo;
DataInfo dataInfoAr[103];
int dataInfoArSz;

bool _isSmallerString(char *str1, char *str2) {

    int i = 0;
    for(i=0; str1[i] && str2[i]; i++) {
        if(str1[i] < str2[i]) return true;
        if(str1[i] > str2[i]) return false;
    }
    if(str1[i] < str2[i]) return true;
    return false;
}

bool _isSameString(char *str1, char *str2) {
    int i = 0;
    for(i=0; str1[i] && str2[i]; i++) {
        if(str1[i] != str2[i]) return false;
    }
    if(str1[i] != str2[i]) return false;
    return true;
}

void _merge(int low, int mid, int high) {
    int left = low, right = mid+1, tempInd = 0;
    DataInfo temp[high-low+1];

    while(left <= mid && right <= high) {

        if( _isSmallerString(dataInfoAr[left].logWords, dataInfoAr[right].logWords) ) {
            temp[tempInd++] = dataInfoAr[left++];
        }
        else if( _isSameString(dataInfoAr[left].logWords, dataInfoAr[right].logWords) &&
             _isSmallerString(dataInfoAr[left].identifier, dataInfoAr[right].identifier) ) {
            temp[tempInd++] = dataInfoAr[left++];
        }
        else {
            temp[tempInd++] = dataInfoAr[right++];
        }
    }
    while(left <= mid) temp[tempInd++] = dataInfoAr[left++];
    while(right <= high) temp[tempInd++] = dataInfoAr[right++];

    for(int i=low, j=0; i<=high; i++, j++) dataInfoAr[i] = temp[j];
}

void _mergeSort(int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        _mergeSort(low, mid);
        _mergeSort(mid+1, high);

        _merge(low, mid, high);
    }
}
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    char **outputOrderedLogs = malloc( sizeof(*outputOrderedLogs) * logsSize);

    int outputOrderedLogsSz = 0;
    dataInfoArSz = 0;
    int digitLogIndex[103], digitLogSz = 0;

    for(int i=0; i<logsSize; i++) {
        DataInfo currInfo;

        int len = 0;
        for(len=0; logs[i][len] && logs[i][len]!=' '; len++) {
            currInfo.identifier[len] = logs[i][len];
        }
        currInfo.identifier[len] = '\0';

        while(logs[i][len] && logs[i][len]==' ') len++;

        if( logs[i][len] && (logs[i][len]>='a' && logs[i][len]<='z') ) {
            int j = 0;
            while(logs[i][len]) {
                currInfo.logWords[j] = logs[i][len];
                j++, len++;
            }
            currInfo.logWords[j] = '\0';
            currInfo.index = i;
            dataInfoAr[dataInfoArSz++] = currInfo;
        }
        else {
            digitLogIndex[digitLogSz++] = i;
        }
    }

    _mergeSort(0, dataInfoArSz-1);

    for(int i=0; i<dataInfoArSz; i++) {
        int len = 0;
        int ind = dataInfoAr[i].index;

        int currLogLen = 0;
        while(logs[ind][currLogLen]) currLogLen++;

        outputOrderedLogs[outputOrderedLogsSz] = malloc(sizeof(outputOrderedLogs) * currLogLen);

        while(logs[ind][len]) {
            outputOrderedLogs[outputOrderedLogsSz][len] = logs[ind][len];
            len++;
        }

        outputOrderedLogs[outputOrderedLogsSz][len] = '\0';
        outputOrderedLogsSz++;
    }

    for(int i=0; i<digitLogSz; i++) {
        int ind = digitLogIndex[i];
        int len = 0;
        int currLogLen = 0;
        while(logs[ind][currLogLen]) currLogLen++;

        outputOrderedLogs[outputOrderedLogsSz] = malloc(sizeof(outputOrderedLogs) * currLogLen);

        while(logs[ind][len]) {
            outputOrderedLogs[outputOrderedLogsSz][len] = logs[ind][len];
            len++;
        }
        outputOrderedLogs[outputOrderedLogsSz][len] = '\0';
        outputOrderedLogsSz++;
    }

    *returnSize = outputOrderedLogsSz;
    return outputOrderedLogs;
}
