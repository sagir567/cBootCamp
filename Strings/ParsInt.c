
int ParasInt(char* str){
 int sigen = 1;
if(*str == '-'){
	sigen = -1;
	str++;
}
 int res = 0;
 //str++; // remove this
 while(*str){
 res*=10;
 //res+= *str;
 res+= *str - '0'; //the '0' is a char
 str++;
 }
 return res*sigen;
}