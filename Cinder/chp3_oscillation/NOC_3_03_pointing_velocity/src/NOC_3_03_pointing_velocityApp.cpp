#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_03_pointing_velocityApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	
	Mover mMover;
	bool mousePressed;
};

void NOC_3_03_pointing_velocityApp::prepareSettings(cinder::app::AppBasic::Settings *settings)
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_03_pointing_velocityApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
	Vec2f startLoc = Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) );
	mMover = Mover( startLoc );
}

void NOC_3_03_pointing_velocityApp::mouseDown(cinder::app::MouseEvent event)
{
	mousePressed = true;
}

void NOC_3_03_pointing_velocityApp::mouseUp(cinder::app::MouseEvent event)
{
	mousePressed = false;
}

void NOC_3_03_pointing_velocityApp::update()
{
	// trail version
	if( mousePressed )
	{
		mMover.update( getMousePos() );
		mMover.checkEdges();
	}
	
	/*
	// no trail version
	mMover.update( getMousePos() );
	mMover.checkEdges();*/
}

void NOC_3_03_pointing_velocityApp::draw()
{
	// trail version
	if( mousePressed )
	{
		gl::enableAlphaBlending();
		gl::color( ColorA8u::gray( 255, 5 ) );
		gl::drawSolidRect( getWindowBounds() );
		mMover.display();
	}
	
	/*
	// no trail version
	gl::clear( Color( 1, 1, 1 ) );
	mMover.display();*/	
	
}

CINDER_APP_BASIC( NOC_3_03_pointing_velocityApp, RendererGl )
