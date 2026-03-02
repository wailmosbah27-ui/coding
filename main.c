#include <stdio.h>

int main(){
    //READING A FILE..
    FILE *pFile = fopen("C:\\Users\\SOMODAL\\OneDrive - UWE Bristol\\Desktop\\list.txt", "r");
    char buffer[1024] = {0};

    if(pFile == NULL){
        printf("cannot open file\n");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    fclose(pFile);
    return 0;
}


//WRITING IN A FILE A FILE..
/*
FILE *pFile = fopen("C:\\Users\\SOMODAL\\OneDrive - UWE Bristol\\Desktop\\output.txt", "w");

char text[] = "hallo guys";

if(pFile == NULL){
    printf("Error opening file!\n");
    return 1;
}

fprintf(pFile, "%s", text);
printf("file was written successfully!\n");

fclose(pFile);
*/