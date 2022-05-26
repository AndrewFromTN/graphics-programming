#ifndef TEXTURE
#define TEXTURE

struct TextureBind
{
    unsigned int* texture;
    bool bound;
};

class Texture
{
    private:
        unsigned int texture;
        unsigned int texture_width;
        unsigned int texture_height;
        unsigned int texture_channels;

        bool bind_texture(unsigned char* texture_data);
    public:
        Texture(unsigned int texture_width, unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data);
        ~Texture();

        unsigned int getTexture() const;
};

#endif