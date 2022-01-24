#include "Button.h"
void Button::change_position(double x, double y) {
    posx = x;
    posy = y;
}
void Button::setText(Text* font, std::string text , float scale , float R, float G, float B) {
    font->drawText(text, posx - 40, posy, scale, glm::vec3(R,G,B));
}
Button::Button(Shader* _shader, WINDOW* _windowobj , double _posx, double _posy, double _scale, int _slot , std::string PATH) {
    VAO = new VertexArrayObject(PATH.c_str());
    shader = _shader;
    windowobj = _windowobj;
    posx = _posx;
    posy = _posy;
    scale = _scale;
    frames = &frames__;
    slot = _slot;
}

void Button::create_button(Shader* texture_shader, WINDOW* windowobj, VertexArrayObject* VAO, TEXTURE* texture,
    double posx, double posy, double scale, int* slot) {

    texture_shader->use();
    if (*frames > 10) { texture_shader->setBool("changeColor", false); windowobj->slot[*slot] = false; *frames = 0; }
    else if (windowobj->slot[*slot]) {
        /*
        NOTE: for some reason changing uniform works only from mainloop and only if its directly like this
        because the uniform should be updated every frame!
        should note for future button slots implementation

        */
        texture_shader->setBool("changeColor", true);
        *frames = *frames + 1;

    }

    //rendering object1
    texture_shader->transform(windowobj->window, posx, posy, scale , "notblock");
    texture->use(); // pick texture
    VAO->use(); // pick vao
    DRAW(6); // draw 6 vertices
    texture_shader->setBool("changeColor", false);

}
void Button::render() {
    create_button(shader, windowobj, VAO, &texture , posx, posy, scale, &slot);
}