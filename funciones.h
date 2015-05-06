//extern "C" void errors();

void error();
void errors();
void sets();
void showsets();
void showset();
void refreshTokens();
void storeToken(char *);
void doUnion();
void doIntersect();
void setUnion();
void setIntersect();
void set();


#ifdef __cplusplus

	extern "C" void exitProgram();

#else
	void exitProgram();

#endif
