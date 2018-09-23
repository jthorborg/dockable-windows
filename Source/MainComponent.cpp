/*
==============================================================================

This file was auto-generated!

==============================================================================
*/

#include "MainComponent.h"

namespace jcredland
{
	using namespace juce;

	MainContentComponent::MainContentComponent()
	{
		setSize(700, 400);
		addAndMakeVisible(dock);
		addAndMakeVisible(tabDock);
		addAndMakeVisible(advancedDock);
		auto baseColour = Colours::blue.withSaturation(0.4f).withBrightness(0.4f);
		dock.addComponentToDock(new ExampleDockableComponent("Output", baseColour.withRotatedHue(0.1f)));
		dock.addComponentToDock(new ExampleDockableComponent("Session", baseColour.withRotatedHue(0.2f)));
		dock.addComponentToDock(new ExampleDockableComponent("Notepad", baseColour.withRotatedHue(0.3f)));

		tabDock.addComponentToDock(new ExampleDockableComponent("Database View", baseColour.withRotatedHue(0.6f)));
		tabDock.addComponentToDock(new ExampleDockableComponent("Folder View", baseColour.withRotatedHue(0.7f)));

		advancedDock.addComponentToNewRow(new ExampleDockableComponent("Extra View", baseColour.withRotatedHue(0.9f)), 0);
		advancedDock.addComponentToDock(new ExampleDockableComponent("Another View", baseColour.withRotatedHue(0.85f)));
		advancedDock.addComponentToNewRow(new ExampleDockableComponent("Top", baseColour.withRotatedHue(0.85f)), 0);
		advancedDock.addComponentToNewRow(new ExampleDockableComponent("Bottom", baseColour.withRotatedHue(0.85f)), -1);
	}

	MainContentComponent::~MainContentComponent()
	{
	}

	void MainContentComponent::paint(Graphics& g)
	{
		g.fillAll(Colours::black);
	}

	void MainContentComponent::resized()
	{
		auto area = getLocalBounds();
		dock.setBounds(area.removeFromLeft(150).reduced(4));
		tabDock.setBounds(area.removeFromRight(250).reduced(4));
		advancedDock.setBounds(area.reduced(4));
	}


}