build:
	./build.sh $(PROB)
run: build
	./src/a.out
nb-run:
	./src/a.out
clean:
	rm -f src/a.out
	./clean.sh
debug:
	gdb ./src/a.out
test:
# 	Run python file with argument PROB to generate test cases.
# 	For real use, we run `make test PROB=your_problem_name`
	echo "Building Test for $(PROB)"
	python3 tests/test_generator.py $(PROB)