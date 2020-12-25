#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    fp = fopen("creds.txt", "r+");
    char user[256], pass[256], balance[256], buffer[256];
    memset(user, '\0', 256);
    memset(pass, '\0', 256);
    memset(balance, '\0', 256);
    memset(buffer, '\0', 256);

    while(1){
    	//To read space-separated values
        fscanf(fp, "%s %s %s", user, pass, balance);
        if(feof(fp)) break;
        printf("%s %s %s\n", user, pass, balance); //Store each line in file
    }
    
    fseek(fp, 0, SEEK_SET); // Go to start of File or use rewind(fp);
    //To read \n separated values
    fgets(buffer, 256, fp);
    fputs(buffer, stdout);
    
    fseek(fp, 0, SEEK_END); // Go to end of file
    fprintf(fp, "%s %s %s\n", user, pass, balance);
    fclose(fp);
}
