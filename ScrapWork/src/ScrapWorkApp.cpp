//Rosa was here


#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ScrapWorkApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void ScrapWorkApp::setup()
{
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
}

CINDER_APP( ScrapWorkApp, RendererGl )
