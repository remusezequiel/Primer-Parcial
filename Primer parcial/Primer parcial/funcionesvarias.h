#define INTENTS 5
#define LEN_AUX 500

///////////////PROTOTIPOS///////////////////////////////
int generarNextId(void);
int getId(int size);
int getOption(char* message,char* errorMessage,int lowLimitOption, int hiLimitOption);
int getAnswer(char* message, char* errorMessage, char afirmativeChar, char negativeChar);
/*******************DESIGN FUNCTIONS********************/
void line(void);
void lineaPunteada(void);
void largeLine(void);
void optionMenu(void);
/*******************************************************/
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/***********GET FUNCTIONS*******************************/

int getInt(char* message);
float getFloat(char* message);
char getChar(char* message);
void getString(char* message,char* chargeArray);
void optionMenu(void);

/*********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/**********VALIDATION FUNCTIONS***************************************************************/


int itsNumericWhitFloat(char* string);
int itsNumericString(char* string);
int isLettersString(char* string);


/***********************************************************************************************************/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**********GET VALIDATION FUNCTIONS*************************************************************************/

int getLetterString(char* message,char* chargeArray);
int getLetersString(char* message,char* chargeArray);
int getNumberString(char* message,char* chargeArray);
int getStringsOf_float(char* message,char* chargeArray);
int getLimitedString(char* message,char* errorMessage,char* array,int maxSize);
int getValidInt(char* message,char* errorMessage, char* errorMessageSize, int* number,int downLimitSize, int upLimitSize);
int getValidFloat(char* message,char* errorMessage, float* input, float downLimitSize, float upLimitSize);
int getValidString(char* message,char* errorMessage, char* sizeErrorMessage,char* chargeArray, int maxSize);


/**********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/********************SHOW FUNCTIONS************************************************************/

int showMessageInt(char* message,int showInt);
float showMessageFloat_2(char* message,float showFloat);
float showMessageFloat_3(char* message,float showFloat);
float showMessageFloat_4(char* message,float showFloat);
char showCharacter(char* message, char character);
int showString(char* errorMessage,char* chargeArray,int chargeArraySize);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
