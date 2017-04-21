//
//  PreviewPanel.cpp
//  ScrapWork
//
//  Created by Neil on 4/21/17.
//
//

#include "PreviewPanel.hpp"
using namespace ci;
using namespace ci::app;
using namespace std;

PreviewPanelRef PreviewPanel::create(ci::gl::TextureRef frameTexture)
{
    PreviewPanelRef ref = std::shared_ptr<PreviewPanel>(new PreviewPanel);
    ref->setup(frameTexture);
    return ref;
}

PreviewPanel::PreviewPanel(){}

void PreviewPanel::setup(ci::gl::TextureRef frameTexture)
{
    mFrameTexture = frameTexture;
    mPFrameImg = po::scene::Image::create(frameTexture);
    mPFrameImg->setPosition(ci::vec2(0, 180));
    
    //mRect = po::scene::Shape::createRect():
    
    
    addChild(mPFrameImg);
}
