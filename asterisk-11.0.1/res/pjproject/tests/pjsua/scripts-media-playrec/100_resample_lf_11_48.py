# $Id: 100_resample_lf_11_48.py 369517 2012-07-01 17:28:57Z file $
#
from inc_cfg import *

# simple test
test_param = TestParam(
		"Resample (large filter) 11 KHZ to 48 KHZ",
		[
			InstanceParam("endpt", "--null-audio --quality 10 --clock-rate 48000 --play-file wavs/input.11.wav --rec-file wavs/tmp.48.wav")
		]
		)
