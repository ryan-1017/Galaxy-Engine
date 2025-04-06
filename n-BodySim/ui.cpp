#include "UI.h"

void UI::uiLogic(UpdateParameters& myParam, UpdateVariables& myVar){

	if (myVar.isRecording) {
		DrawRectangleLinesEx({ 0,0, (float)myVar.screenWidth, (float)myVar.screenHeight }, 3, RED);
	}

	toggleSettingsButtons[0].pos = { static_cast<float>(myVar.screenWidth) - 34.0f, 65.0f };
	bool buttonShowSettingsHovering = toggleSettingsButtons[0].buttonLogic(showSettings);

	if (IsKeyPressed(KEY_U)) {
		showSettings = !showSettings;
	}

	DrawTriangle(
		{ toggleSettingsButtons[0].pos.x + 3.0f, toggleSettingsButtons[0].pos.y + 5.0f },
		{ toggleSettingsButtons[0].pos.x + 7.0f, toggleSettingsButtons[0].pos.y + 11.0f },
		{ toggleSettingsButtons[0].pos.x + 11.0f ,toggleSettingsButtons[0].pos.y + 5.0f }, WHITE);

	if (myVar.timeStepMultiplier == 0.0f) {
		DrawRectangleV({ myVar.screenWidth - 200.0f, 20.0f }, { 10.0f, 30.0f }, WHITE);
		DrawRectangleV({ myVar.screenWidth - 220.0f, 20.0f }, { 10.0f, 30.0f }, WHITE);
	}


	if (showSettings) {

		settingsButtonsArray[0].pos = {static_cast<float>(myVar.screenWidth) - 195.0f, 80.0f};
		for (size_t i = 1; i < settingsButtonsArray.size(); ++i) {
			settingsButtonsArray[i].pos.x = settingsButtonsArray[i - 1].pos.x;
			settingsButtonsArray[i].pos.y = settingsButtonsArray[i - 1].pos.y + settingsButtonsArray[i].size.y + 20;
			settingsButtonsArray[i].size = settingsButtonsArray[i - 1].size;

		}
		bool buttonPixelDrawingHovering = settingsButtonsArray[0].buttonLogic(myVar.isPixelDrawingEnabled);
		bool buttonGlobalTrailsHovering = settingsButtonsArray[1].buttonLogic(myVar.isGlobalTrailsEnabled);
		bool buttonSelectedTrailsHovering = settingsButtonsArray[2].buttonLogic(myVar.isSelectedTrailsEnabled);
		bool buttonLocalTrailsHovering = settingsButtonsArray[3].buttonLogic(myVar.isLocalTrailsEnabled);
		bool buttonWhiteTrailsHovering = settingsButtonsArray[4].buttonLogic(myParam.trails.whiteTrails);
		bool buttonSolidColorHovering = settingsButtonsArray[5].buttonLogic(myParam.colorVisuals.solidColor);
		bool buttonDensityColorHovering = settingsButtonsArray[6].buttonLogic(myParam.colorVisuals.densityColor);
		bool buttonVelocityColorHovering = settingsButtonsArray[7].buttonLogic(myParam.colorVisuals.velocityColor);
		bool buttonSelectedColorHovering = settingsButtonsArray[8].buttonLogic(myParam.colorVisuals.selectedColor);
		bool buttonDarkMatterHovering = settingsButtonsArray[9].buttonLogic(myVar.isDarkMatterEnabled);
		bool buttonPeriodicBoundaryHovering = settingsButtonsArray[10].buttonLogic(myVar.isPeriodicBoundaryEnabled);
		bool buttonBarnesHutHovering = settingsButtonsArray[11].buttonLogic(myVar.isBarnesHutEnabled);
		bool buttonMultiThreadingHovering = settingsButtonsArray[12].buttonLogic(myVar.isMultiThreadingEnabled);
		bool buttonCollisionsHovering = settingsButtonsArray[13].buttonLogic(myVar.isCollisionsEnabled);
		bool buttonDensitySizeHovering = settingsButtonsArray[14].buttonLogic(myVar.isDensitySizeEnabled);
		bool buttonControlsHovering = settingsButtonsArray[15].buttonLogic(myParam.controls.isShowControlsEnabled);

		slidersArray[0].sliderPos = { 20, static_cast<float>(myVar.screenHeight) - 530.0f };
		for (size_t i = 1; i < slidersArray.size(); ++i) {
			slidersArray[i].sliderPos.x = slidersArray[i - 1].sliderPos.x;
			slidersArray[i].sliderPos.y = slidersArray[i - 1].sliderPos.y + slidersArray[i].sliderSize.y + 34;
			slidersArray[i].sliderSize = slidersArray[i - 1].sliderSize;
		}

		bool sliderRedHovering = slidersArray[0].sliderLogic(0, myParam.colorVisuals.densityR, 255);
		bool sliderGreenHovering = slidersArray[1].sliderLogic(0, myParam.colorVisuals.densityG, 255);
		bool sliderBlueHovering = slidersArray[2].sliderLogic(0, myParam.colorVisuals.densityB, 255);
		bool sliderAlphaHovering = slidersArray[3].sliderLogic(0, myParam.colorVisuals.densityA, 255);
		bool sliderDensityHovering = slidersArray[4].sliderLogic(0.0f, myParam.colorVisuals.densityRadius, 30.0f);
		bool sliderMaxNeighborsHovering = slidersArray[5].sliderLogic(0, myParam.colorVisuals.maxNeighbors, 300);
		bool sliderSofteningHovering = slidersArray[6].sliderLogic(0.1f, myVar.softening, 30.0f);
		bool sliderThetaHovering = slidersArray[7].sliderLogic(0.1f, myVar.theta, 5.0f);
		bool sliderTimeScaleHovering = slidersArray[8].sliderLogic(0.0f, myVar.timeStepMultiplier, 5.0f);
		bool sliderGravityStrengthHovering = slidersArray[9].sliderLogic(0.0f, myVar.gravityMultiplier, 3.0f);
		bool sliderTrailsLengthHovering = slidersArray[10].sliderLogic(0, myVar.trailMaxLength, 400);
		bool sliderTrailsThicknessHovering = slidersArray[11].sliderLogic(0.007f, myParam.trails.trailThickness, 0.5f);
		bool sliderParticlesSizeHovering = slidersArray[12].sliderLogic(0.1f, myVar.particleSizeMultiplier, 5.0f);


		if (buttonPixelDrawingHovering ||
			buttonDarkMatterHovering ||
			buttonPeriodicBoundaryHovering ||
			buttonGlobalTrailsHovering ||
			buttonBarnesHutHovering ||
			buttonMultiThreadingHovering ||
			buttonSolidColorHovering ||
			buttonDensityColorHovering ||
			buttonVelocityColorHovering ||
			buttonShowSettingsHovering ||
			sliderRedHovering ||
			sliderGreenHovering ||
			sliderBlueHovering ||
			sliderAlphaHovering ||
			sliderDensityHovering ||
			sliderMaxNeighborsHovering ||
			sliderSofteningHovering ||
			sliderThetaHovering ||
			sliderTimeScaleHovering ||
			buttonCollisionsHovering ||
			sliderGravityStrengthHovering ||
			buttonControlsHovering ||
			buttonSelectedTrailsHovering ||
			sliderTrailsLengthHovering ||
			buttonLocalTrailsHovering ||
			buttonDensitySizeHovering ||
			sliderParticlesSizeHovering ||
			buttonSelectedColorHovering ||
			sliderTrailsThicknessHovering ||
			buttonWhiteTrailsHovering
			) {
			myVar.isMouseNotHoveringUI = false;
			myVar.isDragging = false;
		}
		else {
			myVar.isMouseNotHoveringUI = true;
		}

		if (buttonSolidColorHovering && IsMouseButtonPressed(0)) {
			myParam.colorVisuals.velocityColor = false;
			myParam.colorVisuals.densityColor = false;
		}
		if (buttonDensityColorHovering && IsMouseButtonPressed(0)) {
			myParam.colorVisuals.velocityColor = false;
			myParam.colorVisuals.solidColor = false;
		}
		if (buttonVelocityColorHovering && IsMouseButtonPressed(0)) {
			myParam.colorVisuals.densityColor = false;
			myParam.colorVisuals.solidColor = false;
		}

		if (buttonGlobalTrailsHovering && IsMouseButtonPressed(0)) {
			myVar.isSelectedTrailsEnabled = false;
			myParam.trails.trailDots.clear();
		}
		if (buttonSelectedTrailsHovering && IsMouseButtonPressed(0)) {
			myVar.isGlobalTrailsEnabled = false;
			myParam.trails.trailDots.clear();
		}

		myParam.controls.showControls(myVar.isMouseNotHoveringUI, myVar.isDragging, myVar.screenWidth, myVar.screenHeight);
	}
	else {

		if (buttonShowSettingsHovering) {
			myVar.isMouseNotHoveringUI = false;
		}
		else {
			myVar.isMouseNotHoveringUI = true;
		}
	}

	myParam.rightClickSettings.rightClickMenu(myVar.isMouseNotHoveringUI, myVar.isDragging, myParam.subdivision, myParam.particleSelection,
		myParam.myCamera, myParam.particleDeletion, myVar.drawZCurves, myVar.drawQuadtree);

	DrawText(TextFormat("Particles: %i", myParam.pParticles.size()), 50, 50, 25, WHITE);
	if (myParam.pParticlesSelected.size() > 0) {
		DrawText(TextFormat("Selected Particles: %i", myParam.pParticlesSelected.size()), 400, 50, 25, WHITE);
	}

	if (GetFPS() >= 60) {
		DrawText(TextFormat("FPS: %i", GetFPS()), myVar.screenWidth - 150, 50, 18, GREEN);

	}
	else if (GetFPS() < 60 && GetFPS() > 30) {
		DrawText(TextFormat("FPS: %i", GetFPS()), myVar.screenWidth - 150, 50, 18, YELLOW);
	}
	else {
		DrawText(TextFormat("FPS: %i", GetFPS()), myVar.screenWidth - 150, 50, 18, RED);
	}
}
