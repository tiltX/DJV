<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="cs_CZ">
<context>
    <name>djvConvertApplication</name>
    <message>
        <source>-mirror_h</source>
        <translation>-mirror_h</translation>
    </message>
    <message>
        <source>-mirror_v</source>
        <translation>-mirror_v</translation>
    </message>
    <message>
        <source>-scale</source>
        <translation>-scale</translation>
    </message>
    <message>
        <source>-scale_xy</source>
        <translation>-scale_xy</translation>
    </message>
    <message>
        <source>-resize</source>
        <translation>-resize</translation>
    </message>
    <message>
        <source>-width</source>
        <translation>-width</translation>
    </message>
    <message>
        <source>-height</source>
        <translation>-height</translation>
    </message>
    <message>
        <source>-crop</source>
        <translation>-crop</translation>
    </message>
    <message>
        <source>-crop_percent</source>
        <translation>-crop_percent</translation>
    </message>
    <message>
        <source>-channel</source>
        <translation>-channel</translation>
    </message>
    <message>
        <source>-seq</source>
        <translation>-seq</translation>
    </message>
    <message>
        <source>-q</source>
        <translation>-q</translation>
    </message>
    <message>
        <source>-layer</source>
        <translation>-layer</translation>
    </message>
    <message>
        <source>-proxy</source>
        <translation>-proxy</translation>
    </message>
    <message>
        <source>-time</source>
        <translation>-time</translation>
    </message>
    <message>
        <source>-slate</source>
        <translation>-slate</translation>
    </message>
    <message>
        <source>-timeout</source>
        <translation>-timeout</translation>
    </message>
    <message>
        <source>-pixel</source>
        <translation>-pixel</translation>
    </message>
    <message>
        <source>-speed</source>
        <translation>-speed</translation>
    </message>
    <message>
        <source>-tag</source>
        <translation>-tag</translation>
    </message>
    <message>
        <source>-tags_auto</source>
        <translation>-tags_auto</translation>
    </message>
    <message>
        <source>Input</source>
        <translation type="obsolete">Vstup</translation>
    </message>
    <message>
        <source>Output</source>
        <translation type="obsolete">Výstup</translation>
    </message>
    <message>
        <source>Cannot open image: &quot;%1&quot;</source>
        <translation>Nelze otevřít obrázek: &quot;%1&quot;</translation>
    </message>
    <message>
        <source>Cannot open slate: &quot;%1&quot;</source>
        <translation>Nelze otevřít údaje na klapce: &quot;%1&quot;</translation>
    </message>
    <message>
        <source>djv_convert

    This application provides a command line tool for processing images and movies.

Usage

    djv_convert (input) (output) [option]...

Conversion Options

    -mirror_h
    -mirror_v
        Mirror the image horizontally or vertically.
    -scale (value)
    -scale_xy (x) (y)
        Scale the image.
    -resize (width) (height)
        Resize the image.
    -width (value)
    -height (value)
        Resize the width or height of the image maintaining the aspect ratio.
    -crop (x) (y) (width) (height)
        Crop the image.
    -crop_percent (x) (y) (width) (height)
        Crop the image as a percentage.
    -channel (value)
        Show only specific image channels. Options = %1. Default = %2.
    -seq, -q (value)
        Set whether file sequencing is enabled. Options = %3. Default = %4.

Input Options

    -layer (value)
        Set the input layer.
    -proxy (value)
        Set the proxy scale. Options = %5. Default = %6.
    -time (start) (end)
        Set the start and end time.
    -slate (input) (frames)
        Set the slate.
    -timeout (value)
        Set the maximum number of seconds to wait for each input frame. Default = %7.

Output Options

    -pixel (value)
        Convert the pixel type. Options = %8.
    -speed (value)
        Set the speed. Options = %9.
    -tag (name) (value)
        Set an image tag.
    -tags_auto (value)
        Automatically generate image tags (e.g., timecode). Options = %10. Default = %11.
%12
Examples

    Convert an image:
    &gt; djv_convert input.sgi output.tga

    Convert an image sequence. Note that only the first frame of the output is specified:
    &gt; djv_convert input.1-100.sgi output.1.tga

    Create an RLE compressed image sequence:
    &gt; djv_convert input.1-100.sgi output.1.tga -targa_compression rle

    Convert an image sequence to a movie:
    &gt; djv_convert input.0001-0100.dpx output.mov

    Convert a movie to an image sequence:
    &gt; djv_convert input.mov output.1.tga

    Convert the pixel type:
    &gt; djv_convert input.sgi output.sgi -pixel &quot;rgb u16&quot;

    Scale an image by half:
    &gt; djv_convert input.tga output.tga -scale 0.5

    Resize an image:
    &gt; djv_convert input.tga output.tga -resize 2048 1556

    Convert a Cineon file to a linear format using the default settings:
    &gt; djv_convert input.cin output.tga

    Convert a Cineon file to a linear format using custom print settings (black point, white point, gamma, and soft clip):
    &gt; djv_convert input.cin output.tga -cineon_input_film_print 95 685 2.2 10
</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Timeout...</source>
        <translation>Časové omezení...</translation>
    </message>
    <message>
        <source>%1 %2</source>
        <translation>%1 %2</translation>
    </message>
    <message>
        <source>Slating...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>[%1%] Estimated = %2 (%3 Frames/Second)</source>
        <translation>[%1%] Odhadováno = %2 (%3 snímky/sekundy)</translation>
    </message>
    <message>
        <source>[100%] </source>
        <translation>[100%] </translation>
    </message>
    <message>
        <source>Elapsed = %1</source>
        <translation>Uplynulo = %1</translation>
    </message>
    <message>
        <source>%1x%2:%3 %4 %5@%6</source>
        <translation>%1x%2:%3 %4 %5@%6</translation>
    </message>
    <message>
        <source>input</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Cannot read image: &quot;%1&quot;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Cannot write image: &quot;%1&quot;</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
