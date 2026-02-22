#include <stdio.h>

void writeFile(){
	
    // write to file
    // write file as fp
    FILE *fp;
    
    //open file path and in write mode
    fp = fopen("D:\\ECPI\\codes\\FinalSDC255\\test.txt", "w+");

	// checking if file open correctly and if not print error and stop 
    if (fp == NULL)
    {
        printf("Error opening file..."); 
		return;
    }
    
    // write to file
    fprintf(fp, "This is testing fprintf...\n");
    fputs("This is testing for fputs...\n", fp);

	// close file after writing
    fclose(fp);
    printf("File has been written...\n");
}

void readFile(){
	// read file
	
	FILE *fp;
	
    // reopen write file but this time as read mode
    fp = fopen("D:\\ECPI\\codes\\FinalSDC255\\test.txt", "r");
    
    // checking if file open correctly and if not print error and stop 
    if (fp == NULL)
    {
        printf("Error opening file..."); 
		return;
    }
    
    // how many characters you can read per line
    char buff[255];
    
    fscanf(fp, "%s", buff);
	printf("1 : %s\n", buff );
	
    //read the rest of line 1
    fgets(buff, 255, fp);
    printf("2 : %s\n", buff);
    
    //read all of the second line
    fgets(buff, 255, fp);
    printf("3 : %s\n", buff);
    
    //close file
    fclose(fp);
}
int main()
{
    writeFile();
    
    readFile();
    
    printf("Press enter to exit");
    getchar();
    
    return 0;
}
