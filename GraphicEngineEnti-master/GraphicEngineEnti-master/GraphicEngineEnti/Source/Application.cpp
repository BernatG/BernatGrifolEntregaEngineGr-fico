#include "precompiledHeader.h"
#include "../Engine.h"

int main()
{
	if (!Engine::get().start())
	{
		assert(0);
	}
	Engine::get().doFrame();

	Engine::get().stop();

	return 0;
}