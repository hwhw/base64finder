# base64finder

Simple heuristical tool that will return an error value indicating whether
data on its standard input might contain base64 encoded data.

No configuration yet except for the source code.

Will return error value 0 (true) when 50 consecutive chars are found that
are valid base64 data representations.
