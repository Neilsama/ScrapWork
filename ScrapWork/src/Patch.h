//
//  Patch.hpp
//  ScrapWork
//
//  Created by Neil on 4/21/17.
//
//

#ifndef Patch_h
#define Patch_h

#include <stdio.h>
#include "poNodeContainer.h"
#include "poImage.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Patch;
typedef std::shared_ptr<Patch> PatchRef;

class Patch
:public po::scene::NodeContainer
{

public:
    static PatchRef create(ci::gl::TextureRef   patchTexture);

private:
    Patch();
    void  setup(ci::gl::TextureRef   patchTexture);
    
    ci::gl::TextureRef      mPatchexture;
    po::scene::ImageRef     mPPatchImg;

};


#endif /* Patch_hpp */
