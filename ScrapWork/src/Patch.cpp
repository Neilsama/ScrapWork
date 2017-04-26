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

Patch::Patch(){}

void Patch::setup(ci::gl::TextureRef patchTexture)
{
    mPatchexture = patchTexture;
    mPPatchImg = po::scene::Image::create(mPatchexture);
    addChild(mPPatchImg);
}
