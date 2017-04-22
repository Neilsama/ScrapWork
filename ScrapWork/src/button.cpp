//
//  button.cpp
//  ScrapWork
//
//  Created by Neil on 4/21/17.
//
//

#include "button.hpp"
#include "PreviewPanel.hpp"
#include "poShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

buttonRef button::create(ci::gl::TextureRef buttonTexture)
{
    buttonRef ref = std::shared_ptr<button>(new button);
    ref->setup(buttonTexture);
    return ref;
}

button::button(){}

void button::setup(ci::gl::TextureRef frameTexture)
{
    // load preview panel frame picture
    mButtonTexture = frameTexture;
    mPButtonImg = po::scene::Image::create(frameTexture);

    addChild(mPButtonImg);
}
