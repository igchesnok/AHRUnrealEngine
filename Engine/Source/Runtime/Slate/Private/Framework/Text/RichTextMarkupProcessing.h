// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once

#if WITH_FANCY_TEXT

#include "IRichTextMarkupParser.h"
#include "IRichTextMarkupWriter.h"

class FDefaultRichTextMarkupParser : public IRichTextMarkupParser
{
public:
	static TSharedRef< FDefaultRichTextMarkupParser > Create();

public:
	virtual void Process(TArray<FTextLineParseResults>& Results, const FString& Input, FString& Output) override;

private:
	FDefaultRichTextMarkupParser() {}

	void ParseLineRanges(const FString& Input, const TArray<FTextRange>& LineRanges, TArray<FTextLineParseResults>& LineParseResultsArray) const;
	void HandleEscapeSequences(const FString& Input, TArray<FTextLineParseResults>& LineParseResultsArray, FString& ConcatenatedUnescapedLines) const;

};

class FDefaultRichTextMarkupWriter : public IRichTextMarkupWriter
{
public:
	static TSharedRef< FDefaultRichTextMarkupWriter > Create();

public:
	virtual void Write(const TArray<FRichTextLine>& InLines, FString& Output) override;

private:
	FDefaultRichTextMarkupWriter() {}
	static void EscapeText(FString& TextToEscape);
};

#endif //WITH_FANCY_TEXT
