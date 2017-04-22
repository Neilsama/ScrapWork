//
//  Patch.cpp
//  ScrapWork
//
//  Created by Neil on 4/21/17.
//
//

#include "Patch.h"
using namespace ci;
using namespace ci::app;
using namespace std;

PatchRef Patch::create(ci::gl::TextureRef patchTexture)
{
    PatchRef ref = std::shared_ptr<Patch>(new Patch);
    ref->setup(patchTexture);
    return ref;
}

Patch::Patch()
:mScale(ci::vec2(0.5)),
isNewOne(false)
{}

void Patch::setup(ci::gl::TextureRef patchTexture)
{
    mPatchexture = patchTexture;
    mPPatchImg = po::scene::Image::create(mPatchexture);
    mPPatchImg->setScale(normalScale);
    addChild(mPPatchImg);
    
    //connect signal
    getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&Patch::onMouseEvent, this, std::placeholders::_1));
    getSignal(po::scene::MouseEvent::UP_INSIDE).connect(std::bind(&Patch::onMouseEvent, this, std::placeholders::_1));
    getSignal(po::scene::MouseEvent::DRAG_INSIDE).connect(std::bind(&Patch::onMouseEvent, this, std::placeholders::_1));

}


void Patch::onMouseEvent(po::scene::MouseEvent &event)
{
    if (isNewOne) {
        switch (event.getType()) {
            case po::scene::MouseEvent::DRAG_INSIDE:
            {
                mPPatchImg->setPosition(event.getLocalPos() - ci::vec2(25));
            }
                
            default:
                break;
        }
    }
    
}










