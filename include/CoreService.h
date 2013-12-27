#ifndef CORESERVICE_H
#define CORESERVICE_H

#include <stdexcept>
using std::runtime_error;

#include <SDL.h>

#include "Service.h"

/**
 * This service initializes the SDL library.
 * 
 * @see Service 
 */
class CoreService : public Service {
	
private:
	Uint32 flags;

public:
	CoreService( Uint32 flags = SDL_INIT_EVERYTHING );
	void init() throw( runtime_error );
	void destroy();
};

#endif
