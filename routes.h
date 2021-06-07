/* routes.h
 *  Routes for web pages stored in Progam memory
 *  
 *  
 */
 
#ifndef routes_
#define routes_

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "http.h"


void serverBegin(void);
void serverOnHome(void);
void serverOnUpdate(void);



#endif  //routes.h
