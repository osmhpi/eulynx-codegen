all: 04_OutputC 03_TransformationReport/out/index.html

clean:
	make -C 01_XMI clean
	rm -rf 04_OutputC

01_XMI/cleaned.xmi:
	make -C 01_XMI

03_TransformationReport/parse-classes-test-result.xml: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\parse-classes-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=parse-classes" || true

03_TransformationReport/generate-c-test-result.xml: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\generate-c-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=generate-c" || true

03_TransformationReport/compile-c-test-result.xml: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\compile-c-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=compile-c" || true

03_TransformationReport/generate-klee-test-result.xml: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\generate-klee-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=generate-klee" || true

03_TransformationReport/compile-klee-test-result.xml: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\compile-klee-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=compile-klee" || true

03_TransformationReport/execute-klee-test-result.xml: 01_XMI/cleaned.xmi
	cd 02_Transformation && CODEGEN_OUTPUT_DIR=$$PWD/../04_OutputC dotnet test --test-adapter-path:. --logger:"junit;LogFilePath=..\03_TransformationReport\execute-klee-test-result.xml;MethodFormat=Class;FailureBodyFormat=Verbose" --filter "TestCategory=execute-klee" || true

03_TransformationReport/out/index.html: 03_TransformationReport/parse-classes-test-result.xml 03_TransformationReport/generate-c-test-result.xml 03_TransformationReport/compile-c-test-result.xml
	cp 03_TransformationReport/*.xml ../utils/testreport/app/\(default\)/dashboard/
	cd ../utils/testreport && npm i && npm run build
	rm -rf 03_TransformationReport/report
	mkdir 03_TransformationReport/report
	cp -r ../utils/testreport/out/* 03_TransformationReport/report/

04_OutputC: 03_TransformationReport/generate-c-test-result.xml
	cd 04_OutputC && find . -iname '*.h' -o -iname '*.c' | xargs clang-format -i
