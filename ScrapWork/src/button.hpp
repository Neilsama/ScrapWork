//
//  button.hpp
//  ScrapWork
//
//  Created by Neil on 4/21/17.
//
//

#ifndef button_hpp
#define button_hpp

#include <stdio.h>
#include "poNodeContainer.h"
#include "poImage.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class button;
typedef std::shared_ptr<button> buttonRef;

class button
:public po::scene::NodeContainer
{
    
public:
    static buttonRef  create(ci::gl::TextureRef   buttonTexture);
    //void update();
    
private:
    button();
    void  setup(ci::gl::TextureRef   buttonTexture);
    ci::gl::TextureRef      mButtonTexture;
    po::scene::ImageRef     mPButtonImg;
};

#endif /* button_hpp */
