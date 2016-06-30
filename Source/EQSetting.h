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

#ifndef __JUCE_HEADER_F1EAC4DC053E5FD8__
#define __JUCE_HEADER_F1EAC4DC053E5FD8__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
struct CustomLookAndFeel    : public LookAndFeel_V3
{
	Slider::SliderLayout getSliderLayout(Slider& slider) override
	{
		// 1. compute the actually visible textBox size from the slider textBox size and some additional constraints
		int space = 20 + font.getHeight() + 5 + 1 + 5;
		int minXSpace = 0;
		int minYSpace = 0;

		Slider::TextEntryBoxPosition textBoxPos = slider.getTextBoxPosition();

		if (textBoxPos == Slider::TextBoxLeft || textBoxPos == Slider::TextBoxRight)
			minXSpace = 30;
		else
			minYSpace = 50;

		Rectangle<int> localBounds = slider.getLocalBounds();

		const int textBoxWidth = jmax(0, jmin(slider.getTextBoxWidth(), localBounds.getWidth() - minXSpace));
		const int textBoxHeight = jmax(0, jmin(slider.getTextBoxHeight(), localBounds.getHeight() - minYSpace));

		Slider::SliderLayout layout;

		// 2. set the textBox bounds

		if (textBoxPos != Slider::NoTextBox)
		{
			if (slider.isBar())
			{
				layout.textBoxBounds = localBounds;
			}
			else
			{
				layout.textBoxBounds.setWidth(textBoxWidth);
				layout.textBoxBounds.setHeight(textBoxHeight);

				if (textBoxPos == Slider::TextBoxLeft)           layout.textBoxBounds.setX(0);
				else if (textBoxPos == Slider::TextBoxRight)     layout.textBoxBounds.setX(localBounds.getWidth() - textBoxWidth);
				else /* above or below -> centre horizontally */ layout.textBoxBounds.setX((localBounds.getWidth() - textBoxWidth) / 2);

				if (textBoxPos == Slider::TextBoxAbove)          layout.textBoxBounds.setY(0);
				else if (textBoxPos == Slider::TextBoxBelow)     layout.textBoxBounds.setY(localBounds.getHeight() - textBoxHeight);
				else /* left or right -> centre vertically */    layout.textBoxBounds.setY((localBounds.getHeight() - textBoxHeight) / 2);
			}
		}

		// 3. set the slider bounds

		layout.sliderBounds = localBounds;

		if (slider.isBar())
		{
			layout.sliderBounds.reduce(1, 1);   // bar border
		}
		else
		{
			if (textBoxPos == Slider::TextBoxLeft)       layout.sliderBounds.removeFromLeft(textBoxWidth);
			else if (textBoxPos == Slider::TextBoxRight) layout.sliderBounds.removeFromRight(textBoxWidth);
			else if (textBoxPos == Slider::TextBoxAbove) layout.sliderBounds.removeFromTop(textBoxHeight);
			else if (textBoxPos == Slider::TextBoxBelow) layout.sliderBounds.removeFromBottom(textBoxHeight + space);

			const int thumbIndent = getSliderThumbRadius(slider);

			if (slider.isHorizontal())    layout.sliderBounds.reduce(thumbIndent, 0);
			else if (slider.isVertical()) layout.sliderBounds.reduce(0, thumbIndent);
		}

		return layout;
	}

	void drawLabel(Graphics& g, Label& label) override {
		label.setFont(Font());
		g.fillAll(label.findColour(Label::backgroundColourId));

		if (!label.isBeingEdited())
		{
			const float alpha = label.isEnabled() ? 1.0f : 0.5f;
			const Font font(getLabelFont(label));

			g.setColour(label.findColour(Label::textColourId).withMultipliedAlpha(alpha));
			g.setFont(font);

			Rectangle<int> textArea(label.getBorderSize().subtractedFrom(label.getLocalBounds()));

			g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
				jmax(1, (int)(textArea.getHeight() / font.getHeight())),
				label.getMinimumHorizontalScale());

			g.setColour(label.findColour(Label::outlineColourId).withMultipliedAlpha(alpha));
		}
		else if (label.isEnabled())
		{
			g.setColour(label.findColour(Label::outlineColourId));
		}

		g.drawRect(label.getLocalBounds());
	};

	Label* createSliderTextBox(Slider& slider) override {
		Label* const l = new Label();

		l->setJustificationType(Justification::centred);
		l->setKeyboardType(TextInputTarget::decimalKeyboard);

		l->setColour(Label::textColourId, slider.findColour(Slider::textBoxTextColourId));
		l->setColour(Label::backgroundColourId,
			(slider.getSliderStyle() == Slider::LinearBar || slider.getSliderStyle() == Slider::LinearBarVertical)
			? Colours::transparentBlack
			: slider.findColour(Slider::textBoxBackgroundColourId));
		l->setColour(Label::outlineColourId, slider.findColour(Slider::textBoxOutlineColourId));
		l->setColour(TextEditor::textColourId, slider.findColour(Slider::textBoxTextColourId));
		l->setColour(TextEditor::backgroundColourId,
			slider.findColour(Slider::textBoxBackgroundColourId)
			.withAlpha((slider.getSliderStyle() == Slider::LinearBar || slider.getSliderStyle() == Slider::LinearBarVertical)
				? 0.7f : 1.0f));
		l->setColour(TextEditor::outlineColourId, slider.findColour(Slider::textBoxOutlineColourId));
		l->setColour(TextEditor::highlightColourId, slider.findColour(Slider::textBoxHighlightColourId));

		return l;
	};
    void drawRoundThumb (Graphics& g, const float x, const float y,
                         const float diameter, const Colour& colour, float outlineThickness)
    {
        const Rectangle<float> a (x, y, diameter, diameter);
        const float halfThickness = outlineThickness * 0.5f;

        Path p;
        p.addEllipse (x + halfThickness, y + halfThickness, diameter - outlineThickness, diameter - outlineThickness);

        const DropShadow ds (Colours::black, 1, Point<int> (0, 0));
        ds.drawForPath (g, p);

        g.setColour (Colours::orange);
        g.fillPath (p);

        g.setColour (Colours::lightgrey);
        g.strokePath (p, PathStrokeType (outlineThickness));
    }

    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        const float sliderRadius = (float) (getSliderThumbRadius (slider) - 2);

        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        Colour knobColour (slider.findColour (Slider::thumbColourId).withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f));

        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;

            if (style == Slider::LinearVertical)
            {
                kx = x + width * 0.5f;
                ky = sliderPos;
            }
            else
            {
                kx = sliderPos;
                ky = y + height * 0.5f;
            }

            const float outlineThickness = slider.isEnabled() ? 0.8f : 0.3f;

            drawRoundThumb (g,
                            kx-5 ,
                            ky-5 ,
                            10,
                            knobColour, 1);
        }
        
    }

    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override
    {
        g.fillAll (slider.findColour (Slider::backgroundColourId));
	      drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
           drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
      
    }

    void drawLinearSliderBackground (Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const Slider::SliderStyle /*style*/, Slider& slider) override
    {
		const float sliderRadius = 2;//getSliderThumbRadius (slider) - 5.0f;
        Path on, off;

        
            const float ix = x + width * 0.5f - sliderRadius * 0.5f;
            Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
            const float onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));

            on.addRectangle (r.removeFromBottom (onH));
            off.addRectangle (r);
      
        g.setColour (Colours::white);
        g.fillPath (on);

        g.setColour (Colours::white);
        g.fillPath (off);
		
		Rectangle<int> localBounds = slider.getLocalBounds();
		localBounds.removeFromBottom(slider.getTextBoxHeight());
		localBounds.removeFromBottom(5);
		Rectangle<float> line(slider.getWidth()*0.5 - 4, localBounds.getBottom(), 8, 1);
		localBounds.removeFromBottom(6);
		localBounds.removeFromBottom(font.getHeight());

		Rectangle<float> text( 0, localBounds.getBottom(), slider.getWidth(), font.getHeight());
		g.setColour(Colours::white);
		g.fillRect(line);
		g.drawText("30",text, Justification::centred, true);

    }

  private:
	  Font font;
};

class EQSetting  : public Component,
                   public SliderListener
{
public:
    //==============================================================================
    EQSetting ();
    ~EQSetting();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
	void createList();


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
	ScopedPointer<Slider> slider;
	ScopedPointer<CustomLookAndFeel> laf;
	OwnedArray<Slider> listSlider;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQSetting)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F1EAC4DC053E5FD8__
