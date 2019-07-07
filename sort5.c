#include "types.h"
#include "user.h"
#include "fcntl.h"
//#include "defs.h"
//#include "proc.h"

/*
void swap(char* x, char* y) 
{ 
    char temp = *x; 
    *x = *y; 
    *y = temp; 
}

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        swap(*(char*)((int)str+start), *(char*)((int)str+end)); 
        start++; 
        end--; 
    } 
} 
  
// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    int isNegative = 0; 
 */ 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
/*
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = 1; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
}
*/

int stoi(const char *s)
{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

void getDecStr(int val, char* str){
  int i;
  int len = 0;
  int temp = val;
  
  while(1){
    temp = temp/10;
    if(temp != 0){
      len++;
    }
    else break;
  }
  len++;
  for(i=1; i<=len; i++)
  {
    str[len-i] = (char)((val % 10) + '0');
    val/=10;
  }
  str[i-1] = '\0';
}

void sort5(char* argv[]){
    
//    printf(1, "%d %d %d %d %d",stoi(argv[1]),argv[2] - '0',argv[3] - '0',argv[4] - '0',argv[5] - '0');
    int array[5];
//    char array2[5];
    char* array3[5];
    int size[5];
    int i, j, num, temp;
 
    num = 5;
    for (i = 0; i < num; i++){
        array[i] = stoi(argv[i+1]);
    }
    for (i = 0; i < num; i++){
        for (j = 0; j < (num - i - 1); j++){
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
//    char temp2[2];
 //   char str3[100];
    for (i = 0; i < num; i++){
          char NumtoChar[5][100];
//        getDecStr(array[i], temp2);
//        array2[i] = temp2;
//          array2[i] = array[i] + '0';

          int j;
	  int len = 0;
	  int temp = array[i];
	  
	  while(1){
	    temp = temp/10;
	    if(temp != 0){
	      len++;
	    }
	    else break;
	  }
	  len++;
          size[i] = len;
//          printf(1, "%d", len);
	  for(j=1; j<=len; j++)
	  {
	    NumtoChar[i][len-j] = (char)((array[i] % 10) + '0');
	    array[i]/=10;
	  }
	  NumtoChar[i][j-1] = '\0';
//          printf(1, " %s ", NumtoChar[i]);
          array3[i] = &NumtoChar[i][0];
    }
//    printf(1, "\n");
//    printf(1, "%s %s %s %s %s",array3[0],array3[1],array3[2],array3[3],array3[4]);
	char space = ' ';
	char enter = '\n';
        int sizeSpace = sizeof(space);
	int fd;
	fd = open("result.txt", O_CREATE | O_RDWR);
//	int size = sizeof(*array3);
	write(fd, &(*array3[0]), size[0]);
        write(fd, &space, sizeSpace);
        write(fd, &(*array3[1]), size[1]);
        write(fd, &space, sizeSpace);
        write(fd, &(*array3[2]), size[2]);
        write(fd, &space, sizeSpace);
        write(fd, &(*array3[3]), size[3]);
        write(fd, &space, sizeSpace);
        write(fd, &(*array3[4]), size[4]);
	write(fd, &enter, sizeof(enter));
	close(fd);

//	printf(1, "%d %d %d %d %d",array[0],array[1],array[2],array[3],array[4]);
	
	printf(1,"PID : %d\n", getpid());
}

int main(int argc, char* argv[]){
	if(argc <= 4){
		exit();
	}
	sort5(argv);
	exit();
}
