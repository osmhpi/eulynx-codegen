all: 04_OutputC

clean:
	make -C 01_XMI clean
	rm -rf 04_OutputC

01_XMI/cleaned.xmi:
	make -C 01_XMI

04_OutputC: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\{assembly}-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=generate-c"
	cd 04_OutputC && find . -iname '*.h' -o -iname '*.c' | xargs clang-format -i
