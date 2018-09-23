
#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "JDockableWindows.h"
#include "JAdvancedDock.h"

namespace jcredland
{
	/// <summary>
	/// A really simple component we can use to test the dragging and docking.
	/// </summary>
	class ExampleDockableComponent : public juce::Component
	{
	public:
		ExampleDockableComponent(const juce::String & componentName, const juce::Colour & colour_)
			: colour(colour_)
		{
			juce::Component::setName(componentName);
		}

		~ExampleDockableComponent()
		{
			jassertfalse;
		}

		void paint(juce::Graphics & g) override
		{
			g.fillAll(colour);
			g.setColour(juce::Colours::white);
			g.drawText("Window Content", getLocalBounds(), juce::Justification::centred, false);
		}

	private:
		juce::Colour colour;
	};



	class MainContentComponent : public juce::Component
	{
	public:
		//==============================================================================
		MainContentComponent();
		~MainContentComponent();

		void paint(juce::Graphics&) override;
		void resized() override;

	private:
		DockableWindowManager dockManager;
		WindowDockVertical dock{ dockManager };
		TabDock tabDock{ dockManager };
		JAdvancedDock advancedDock{ dockManager };

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
	};


}


#endif  // MAINCOMPONENT_H_INCLUDED