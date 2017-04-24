//Rosa was here


#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poScene.h"
#include "poImage.h"
#include "poShape.h"
#include "poNodeContainer.h"

#include "SelectPatchPanel.h"
#include "Patch.h"
#include "PreviewPanel.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class ScrapWorkApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void mouseUp( MouseEvent event )  override;
	void update() override;
	void draw() override;
    
    void generateNewPatch(int number);
    
    po::scene::SceneRef             mScence;
    po::scene::NodeContainerRef     activeContainer;
    
    po::scene::ShapeRef             bgShape; // background shape
    po::scene::ImageRef             bgPImg; // background image
    SelectPatchPanelRef             mSelectPatchPanel; //  select patch panel image
    PreviewPanelRef                 mPreviewPanel; //  preview panel
    
    PatchRef                        newPatch;
    
    std::vector<PatchRef>           patchesQueue; //all patches already add in play panel
};

void ScrapWorkApp::setup()
{
    ci::app::setWindowSize(1280.f, 800.f);
    
    //  create boss container
    
    activeContainer = po::scene::NodeContainer::create();
    mScence = po::scene::Scene::create(activeContainer);
    
    
    //  create background shape and load background image
    bgPImg = po::scene::Image::create(ci::gl::Texture::create(ci::loadImage(loadAsset("bg.png"))));
    
    
    //  create select patch panel
    mSelectPatchPanel = SelectPatchPanel::create(ci::gl::Texture::create(ci::loadImage(loadAsset("bg_selectGrid.png"))));
    mSelectPatchPanel->setInteractionEnabled(true);
    
    //  create preview panel
    mPreviewPanel = PreviewPanel::create(ci::gl::Texture::create(ci::loadImage(loadAsset("bg_preview.png"))));
    
    
    activeContainer->addChild(bgPImg);
    activeContainer->addChild(mSelectPatchPanel);
    activeContainer->addChild(mPreviewPanel);
    
    // connect signal;
    for (int i = 0; i<mSelectPatchPanel->getPatchNum(); i++) {
        mSelectPatchPanel->getPatch(i)->getNewPatchSignal().connect(std::bind(&ScrapWorkApp::generateNewPatch,this, std::placeholders::_1));
    }
    
}

void ScrapWorkApp::generateNewPatch(int number)
{
    newPatch = Patch::create(mSelectPatchPanel->getPatch(number)->getTexture());
    newPatch->setPosition(mSelectPatchPanel->getPatch(number)->getPosition()-ci::vec2(-10));
    activeContainer->addChild(newPatch);

}

void ScrapWorkApp::mouseDown( MouseEvent event )
{
//
//    if (mSelectPatchPanel->isInteractionEnabled()) {
//        for (int i = 0 ; i < mSelectPatchPanel->getPatchNum() ; i++) {
//            if (event.getX() > mSelectPatchPanel->getPatch(i)->getPosition().x
//                && event.getX() < mSelectPatchPanel->getPatch(i)->getPosition().x + 50
//                && event.getY() > mSelectPatchPanel->getPatch(i)->getPosition().y
//                && event.getY() < mSelectPatchPanel->getPatch(i)->getPosition().y+50) {
//                
//                // if generate a new patch
//                mSelectPatchPanel->setInteractionEnabled(false);
//                newPatch = Patch::create(mSelectPatchPanel->getPatch(i)->getTexture());
//                newPatch->setPosition(mSelectPatchPanel->getPatch(i)->getPosition());
//            
//                ci::app::timeline().apply(&newPatch->getScaleAnim(), newPatch->getScale(), newPatch->getScale()+ci::vec2(0.1), 0.3,ci::EaseOutQuad());
//            
//                newPatch->setNewOne(true);
//            
//                activeContainer->addChild(newPatch);
//                
//                }
//            }
//    }
}


void ScrapWorkApp::mouseUp(MouseEvent event)
{
//    // only when hold a patch, select panel is interaction false
//    if (!mSelectPatchPanel->isInteractionEnabled()) {
//
//        // if in play area
//        if (event.getX() > 426 && event.getX() < 926 && event.getY() > 295 && event.getY() < 695)
//        {
//            // if the patch is a new one
//            if(newPatch->isNew())
//            {// if the patch is a new one and drag in the play area
//                patchesQueue.push_back(newPatch);
//                newPatch->setNewOne(false);
//                
//            }else
//                ;// if the patch is not a new one, just change position, here is update position in position vector
//            
//        }
//        
//        // if not in play area, just fade out and delete child
//        else
//        {
//            // if patch not in play area
//            ci::app::timeline().apply(&newPatch->getAlphaAnim(),1.f ,0.f ,0.2 ,ci::EaseInSine());
//        }
//        cout<<"patchesQueue size : "<<patchesQueue.size()<<endl;
//        mSelectPatchPanel->setInteractionEnabled(true);
//    }
//    // if not holding a patch
//    else;
    
}


void ScrapWorkApp::update()
{
    mScence->update();
}

void ScrapWorkApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mScence->draw();

}

CINDER_APP( ScrapWorkApp, RendererGl )
