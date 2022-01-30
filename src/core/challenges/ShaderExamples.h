
#ifndef MINECRAFTCLONE_SHADEREXAMPLES_H
#define MINECRAFTCLONE_SHADEREXAMPLES_H

#include "../../core.h"
#include "../Window.h"

namespace MinecraftClone {
    namespace ShaderExamples {
        void init(const Window& window);
        void destroy();

        void update(float dt);
    };
}


#endif //MINECRAFTCLONE_SHADEREXAMPLES_H
