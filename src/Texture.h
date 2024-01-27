#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

#include "../libs/stb_image.h"

#include <iostream>


class Texture
{
public:
    Texture();
    Texture(const Texture& other);

    operator GLuint();

private:
    GLuint _texture;
};

#endif // TEXTURE_H
