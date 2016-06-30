/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EQSetting.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EQSetting::EQSetting ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::LinearVertical);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 30, 20);
    slider->addListener (this);
	slider->setLookAndFeel(laf = new CustomLookAndFeel());

    //[UserPreSize]
    //[/UserPreSize]
createList();
    setSize (600, 400);

	
    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EQSetting::~EQSetting()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EQSetting::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::green);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EQSetting::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]
	Rectangle<int> r = getLocalBounds();
 //   slider->setBounds (this->getBounds());
	for (auto i : listSlider) {
		i->setBounds(r.removeFromLeft(50));
	}
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EQSetting::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void EQSetting::createList()
{
	for (size_t i = 0; i < 10; i++)
	{
		Slider* sli;// = new Slider();
		addAndMakeVisible(sli = new Slider("new slider"));
		sli->setRange(0, 10, 0);
		sli->setSliderStyle(Slider::LinearVertical);
		sli->setTextBoxStyle(Slider::TextBoxBelow, false, 30, 20);
		sli->addListener(this);
		sli->setLookAndFeel(laf);
		listSlider.add(sli);
	}
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EQSetting" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="f1f5a4d76db3bf88" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="48 40 150 320" min="0" max="10" int="0"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="30" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
