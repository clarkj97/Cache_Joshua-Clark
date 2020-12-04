#pragma once
//Test Sequences for Direct Cache Project


	//SEQ1: Seqence of 150 addresses
	//SEQ2 : Ten address loop executed 15 times
	//SEQ3 : Five address loop executed 30 times
	//SEQ4 : Seventy - five address loop executed 2 times
	//SEQ5 : Five address loop w / thrashing executed 30 times

	//#define SEQ1
	//#define SEQ2
	//#define SEQ3
 //#define SEQ4
#define SEQ5


#ifdef SEQ1
int instruction_sequence[] = {
	 900, 901, 902, 903, 904, 905, 906, 907, 908, 909,
	 910, 911, 912, 913, 914, 915, 916, 917, 918, 919,
	 920, 921, 922, 923, 924, 925, 926, 927, 928 ,929,
	 930, 931, 932, 933, 934, 935, 936, 937, 938, 939,
	 940, 941, 942, 943, 944, 945, 946, 947, 948, 949,
	 950, 951, 952, 953, 954, 955, 956, 957, 958, 959,
	 960, 961, 962, 963, 964, 965, 966, 967, 968, 969,
	 970, 971, 972, 973, 974, 975, 976, 977, 978, 979,
	 980, 981, 982, 983, 984, 985, 986, 987, 988, 989,
	 990, 991, 992, 993, 994, 995, 996, 997, 998, 999,
	 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009,
	 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019,
	 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029,
	 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039,
	 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049 };
#endif
#ifdef SEQ2
int instruction_sequence[] = {
	 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242,
	 1243, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241,
	 1242, 1243, 1234, 1235, 1236, 1237, 1238, 1239, 1240,
	 1241, 1242, 1243, 1234, 1235, 1236, 1237, 1238, 1239,
	 1240, 1241, 1242, 1243, 1234, 1235, 1236, 1237, 1238,
	 1239, 1240, 1241, 1242, 1243, 1234, 1235, 1236, 1237,
	 1238, 1239, 1240, 1241, 1242, 1243, 1234, 1235, 1236,
	 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1234, 1235,
	 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1234,
	 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243,
	 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242,
	 1243, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241,
	 1242, 1243, 1234, 1235, 1236, 1237, 1238, 1239, 1240,
	 1241, 1242, 1243, 1234, 1235, 1236, 1237, 1238, 1239,
	 1240, 1241, 1242, 1243, 1234, 1235, 1236, 1237, 1238,
	 1239, 1240, 1241, 1242, 1243, 1234, 1235, 1236, 1237,
	 1238, 1239, 1240, 1241, 1242, 1243 };
#endif
#ifdef SEQ3
int instruction_sequence[] = {
	 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003,
	 1004, 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002,
	 1003, 1004, 1000, 1001, 1002, 1003, 1004, 1000, 1001,
	 1002, 1003, 1004, 1000, 1001, 1002, 1003, 1004, 1000,
	 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003, 1004,
	 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003,
	 1004, 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002,
	 1003, 1004, 1000, 1001, 1002, 1003, 1004, 1000, 1001,
	 1002, 1003, 1004, 1000, 1001, 1002, 1003, 1004, 1000,
	 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003, 1004,
	 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003,
	 1004, 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002,
	 1003, 1004, 1000, 1001, 1002, 1003, 1004, 1000, 1001,
	 1002, 1003, 1004, 1000, 1001, 1002, 1003, 1004, 1000,
	 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003, 1004,
	 1000, 1001, 1002, 1003, 1004, 1000, 1001, 1002, 1003,
	 1004, 1000, 1001, 1002, 1003, 1004 };
#endif
#ifdef SEQ4
int instruction_sequence[] = {
	 100, 101, 102, 103, 104, 105, 106, 107, 108,
	 109, 110, 111, 112, 113, 114, 115, 116, 117,
	 118, 119, 120, 121, 122, 123, 124, 125, 126,
	 127, 128, 129, 130, 131, 132, 133, 134, 135,
	 136, 137, 138, 139, 140, 141, 142, 143, 144,
	 145, 146, 147, 148, 149, 150, 151, 152, 153,
	 154, 155, 156, 157, 158, 159, 160, 161, 162,
	 163, 164, 165, 166, 167, 168, 169, 170, 171,
	 172, 173, 174, 100, 101, 102, 103, 104, 105,
	 106, 107, 108, 109, 110, 111, 112, 113, 114,
	 115, 116, 117, 118, 119, 120, 121, 122, 123,
	 124, 125, 126, 127, 128, 129, 130, 131, 132,
	 133, 134, 135, 136, 137, 138, 139, 140, 141,
	 142, 143, 144, 145, 146, 147, 148, 149, 150,
	 151, 152, 153, 154, 155, 156, 157, 158, 159,
	 160, 161, 162, 163, 164, 165, 166, 167, 168,
	 169, 170, 171, 172, 173, 174 };
#endif
#ifdef SEQ5
int instruction_sequence[] = {
	 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605,
	 31606, 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511,
	 31605, 31606, 27509, 27510, 27511, 31605, 31606, 27509, 27510,
	 27511, 31605, 31606, 27509, 27510, 27511, 31605, 31606, 27509,
	 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605, 31606,
	 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605,
	 31606, 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511,
	 31605, 31606, 27509, 27510, 27511, 31605, 31606, 27509, 27510,
	 27511, 31605, 31606, 27509, 27510, 27511, 31605, 31606, 27509,
	 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605, 31606,
	 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605,
	 31606, 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511,
	 31605, 31606, 27509, 27510, 27511, 31605, 31606, 27509, 27510,
	 27511, 31605, 31606, 27509, 27510, 27511, 31605, 31606, 27509,
	 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605, 31606,
	 27509, 27510, 27511, 31605, 31606, 27509, 27510, 27511, 31605,
	 31606, 27509, 27510, 27511, 31605, 31606 };
#endif