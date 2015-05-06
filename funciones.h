//extern "C" void errors();

void error();
void errors();
void sets();
void showsets();
void refreshTokens();
void storeToken(char *);

#ifdef __cplusplus

	extern "C" void exitProgram()

#else
	void exitProgram();

#endif