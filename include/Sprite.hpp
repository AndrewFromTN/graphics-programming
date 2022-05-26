#ifndef SPRITE_H
#define SPRITE_H

class Texture;

class Sprite
{
    private:
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;

        float* vertex_data;
        unsigned int* indices;

        int num_components;
        int num_rects;

        Texture* texture;

        void init_render_data();
    public:
        Sprite(float* vertex_data, unsigned int* indices, int num_rects, int num_components, unsigned int texture_width, 
               unsigned int texture_height, unsigned int texture_channels, unsigned char* texture_data);
        ~Sprite();

        unsigned int getVBO() const;
        unsigned int getVAO() const;
        unsigned int getTexture() const;
};

#endif