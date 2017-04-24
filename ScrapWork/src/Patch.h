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
#include "cinder/Signals.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Patch;
typedef std::shared_ptr<Patch> PatchRef;
typedef ci::signals::Signal<void(int number)> newPatchSignal;

class Patch
:public po::scene::NodeContainer
{

public:
    static PatchRef         create(ci::gl::TextureRef   patchTexture);
    void                    onMouseEvent(po::scene::MouseEvent &event);
    newPatchSignal&         getNewPatchSignal(){return mNewPatchSignal;}
    void                    setID(int ID){mID = ID;}
    ci::gl::TextureRef      getTexture(){return mPatchexture;}
    
private:
    Patch();
    void  setup(ci::gl::TextureRef   patchTexture);
    newPatchSignal          mNewPatchSignal;
    int                     mID;
    
    ci::gl::TextureRef      mPatchexture;
    po::scene::ImageRef     mPPatchImg;
    
    ci::vec2                mScale;
    ci::vec2                normalScale = ci::vec2(0.5);
    ci::vec2                activeScale = ci::vec2(0.6);


};


#endif /* Patch_hpp */
