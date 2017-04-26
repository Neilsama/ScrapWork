//Rosa was here


#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poScene.h"
#include "poImage.h"
#include "poShape.h"
#include "poNodeContainer.h"
#include "SelectPatchPanel.h"
#include "PreviewPanel.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class ScrapWorkApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    po::scene::SceneRef             mScence;
    po::scene::NodeContainerRef     activeContainer;
    po::scene::ShapeRef             bgShape;
    
    
    // background image
    po::scene::ImageRef             bgPoImg;
    
    //  select patch panel image
    SelectPatchPanelRef             mSelectPatchPanel;
    
    //  preview panel
    PreviewPanelRef                 mPreviewPanel;
};

void ScrapWorkApp::setup()
{
    ci::app::setWindowSize(1280.f, 800.f);
    
    //  create boss container
    
    activeContainer = po::scene::NodeContainer::create();
    mScence = po::scene::Scene::create(activeContainer);
    
    
    //  create background shape and load background image
    bgPoImg = po::scene::Image::create(ci::gl::Texture::create(ci::loadImage(loadAsset("bg.png"))));
    
    
    //  create select patch panel
    mSelectPatchPanel = SelectPatchPanel::create(ci::gl::Texture::create(ci::loadImage(loadAsset("activePage_selectGrid.png"))));
    
    //  create preview panel
    mPreviewPanel = PreviewPanel::create(ci::gl::Texture::create(ci::loadImage(loadAsset("activePage_previewBagWindow.png"))));
    
    
    activeContainer->addChild(bgPoImg);
    activeContainer->addChild(mSelectPatchPanel);
    activeContainer->addChild(mPreviewPanel);
    
}

void ScrapWorkApp::mouseDown( MouseEvent event )
{
}

void ScrapWorkApp::update()
{
}

void ScrapWorkApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );

    mScence->draw();

}

CINDER_APP( ScrapWorkApp, RendererGl )
