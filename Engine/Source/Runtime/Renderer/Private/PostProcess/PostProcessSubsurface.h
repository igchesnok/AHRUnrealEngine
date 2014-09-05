// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

/*=============================================================================
	PostProcessSubsurface.h: Screenspace subsurface scattering implementation
=============================================================================*/

#pragma once

#include "RenderingCompositionGraph.h"


// ePId_Input0: SceneColor
// derives from TRenderingCompositePassBase<InputCount, OutputCount> 
// uses some GBuffer attributes
// alpha is unused
class FRCPassPostProcessSubsurfaceSetup : public TRenderingCompositePassBase<1, 1>
{
public:
	FRCPassPostProcessSubsurfaceSetup(bool bInVisualize);

	// interface FRenderingCompositePass ---------
	virtual void Process(FRenderingCompositePassContext& Context);
	virtual FPooledRenderTargetDesc ComputeOutputDesc(EPassOutputId InPassOutputId) const;
	virtual void Release() override { delete this; }

	bool bVisualize;
};


// derives from TRenderingCompositePassBase<InputCount, OutputCount>
// ePId_Input0: optional SubsurfaceTemp input
// ePId_Input1: SceneColor (horizontal blur) or the pass before (vertical blur)
// modifies SceneColor, uses some GBuffer attributes
class FRCPassPostProcessSubsurface : public TRenderingCompositePassBase<2, 1>
{
public:
	// constructor
	// @param Pass 0:horizontal/1:vertical
	// @param InRadius in pixels in the full res image
	FRCPassPostProcessSubsurface(uint32 Pass, float InRadius);

	// interface FRenderingCompositePass ---------

	virtual void Process(FRenderingCompositePassContext& Context);
	virtual void Release() override { delete this; }
	virtual FPooledRenderTargetDesc ComputeOutputDesc(EPassOutputId InPassOutputId) const;

private:
	// in pixels in the full res image
	float Radius;
	// 0:horizontal/1:vertical
	uint32 Pass;
};
