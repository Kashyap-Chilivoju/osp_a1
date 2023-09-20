##
 # startup code provided by Paul Miller for COSC1114 - Operating Systems
 # Principles
 ##

CC = g++
CFLAGS = -Wall -Werror -std=c++20 -lpthread
dir1 = copier_files/
dir2 = mtcopier_files/

.PHONY: all

all: copier mtcopier

# provide make targets here to build the two programs

copier: $(dir1)main.cpp $(dir1)reader.cpp $(dir1)writer.cpp
	$(CC) $(CFLAGS) -o $@ $^

mtcopier: $(dir2)main.cpp $(dir2)reader.cpp $(dir2)writer.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f copier mtcopier outfile.txt



runcopier512m_1:
	./copier data.512m outfile.txt
runcopier512m_2:
	./copier data.512m outfile.txt
runcopier512m_3:
	./copier data.512m outfile.txt
runcopier512m_4:
	./copier data.512m outfile.txt
runcopier512m_5:
	./copier data.512m outfile.txt
copier512m: runcopier512m_1 runcopier512m_2 runcopier512m_3 runcopier512m_4 runcopier512m_5

runcopier1g_1:
	./copier data.1g outfile.txt
runcopier1g_2:
	./copier data.1g outfile.txt
runcopier1g_3:
	./copier data.1g outfile.txt
runcopier1g_4:
	./copier data.1g outfile.txt
runcopier1g_5:
	./copier data.1g outfile.txt
copier1g: runcopier1g_1 runcopier1g_2 runcopier1g_3 runcopier1g_4 runcopier1g_5

runcopier2g_1:
	./copier data.2g outfile.txt
runcopier2g_2:
	./copier data.2g outfile.txt
runcopier2g_3:
	./copier data.2g outfile.txt
runcopier2g_4:
	./copier data.2g outfile.txt
runcopier2g_5:
	./copier data.2g outfile.txt
copier2g: runcopier2g_1 runcopier2g_2 runcopier2g_3 runcopier2g_4 runcopier2g_5

runcopier4g_1:
	./copier data.4g outfile.txt
runcopier4g_2:
	./copier data.4g outfile.txt
runcopier4g_3:
	./copier data.4g outfile.txt
runcopier4g_4:
	./copier data.4g outfile.txt
runcopier4g_5:
	./copier data.4g outfile.txt
copier4g: runcopier4g_1 runcopier4g_2 runcopier4g_3 runcopier4g_4 runcopier4g_5

copiertest: copier512m copier1g copier2g copier4g

######################################################################################################

run25mtcopier512m_1:
	./mtcopier 25 data.512m outfile.txt
run25mtcopier512m_2:
	./mtcopier 25 data.512m outfile.txt
run25mtcopier512m_3:
	./mtcopier 25 data.512m outfile.txt
run25mtcopier512m_4:
	./mtcopier 25 data.512m outfile.txt
run25mtcopier512m_5:
	./mtcopier 25 data.512m outfile.txt

25mtcopier512m: run25mtcopier512m_1 run25mtcopier512m_2 run25mtcopier512m_3 run25mtcopier512m_4 run25mtcopier512m_5

run50mtcopier512m_1:
	./mtcopier 50 data.512m outfile.txt
run50mtcopier512m_2:
	./mtcopier 50 data.512m outfile.txt
run50mtcopier512m_3:
	./mtcopier 50 data.512m outfile.txt
run50mtcopier512m_4:
	./mtcopier 50 data.512m outfile.txt
run50mtcopier512m_5:
	./mtcopier 50 data.512m outfile.txt

50mtcopier512m: run50mtcopier512m_1 run50mtcopier512m_2 run50mtcopier512m_3 run50mtcopier512m_4 run50mtcopier512m_5

run75mtcopier512m_1:
	./mtcopier 75 data.512m outfile.txt
run75mtcopier512m_2:
	./mtcopier 75 data.512m outfile.txt
run75mtcopier512m_3:
	./mtcopier 75 data.512m outfile.txt
run75mtcopier512m_4:
	./mtcopier 75 data.512m outfile.txt
run75mtcopier512m_5:
	./mtcopier 75 data.512m outfile.txt

75mtcopier512m: run75mtcopier512m_1 run75mtcopier512m_2 run75mtcopier512m_3 run75mtcopier512m_4 run75mtcopier512m_5

run100mtcopier512m_1:
	./mtcopier 100 data.512m outfile.txt
run100mtcopier512m_2:
	./mtcopier 100 data.512m outfile.txt
run100mtcopier512m_3:
	./mtcopier 100 data.512m outfile.txt
run100mtcopier512m_4:
	./mtcopier 100 data.512m outfile.txt
run100mtcopier512m_5:
	./mtcopier 100 data.512m outfile.txt

100mtcopier512m: run100mtcopier512m_1 run100mtcopier512m_2 run100mtcopier512m_3 run100mtcopier512m_4 run100mtcopier512m_5


run25mtcopier1g_1:
	./mtcopier 25 data.1g outfile.txt
run25mtcopier1g_2:
	./mtcopier 25 data.1g outfile.txt
run25mtcopier1g_3:
	./mtcopier 25 data.1g outfile.txt
run25mtcopier1g_4:
	./mtcopier 25 data.1g outfile.txt
run25mtcopier1g_5:
	./mtcopier 25 data.1g outfile.txt

25mtcopier1g: run25mtcopier1g_1 run25mtcopier1g_2 run25mtcopier1g_3 run25mtcopier1g_4 run25mtcopier1g_5

run50mtcopier1g_1:
	./mtcopier 50 data.1g outfile.txt
run50mtcopier1g_2:
	./mtcopier 50 data.1g outfile.txt
run50mtcopier1g_3:
	./mtcopier 50 data.1g outfile.txt
run50mtcopier1g_4:
	./mtcopier 50 data.1g outfile.txt
run50mtcopier1g_5:
	./mtcopier 50 data.1g outfile.txt

50mtcopier1g: run50mtcopier1g_1 run50mtcopier1g_2 run50mtcopier1g_3 run50mtcopier1g_4 run50mtcopier1g_5

run75mtcopier1g_1:
	./mtcopier 75 data.1g outfile.txt
run75mtcopier1g_2:
	./mtcopier 75 data.1g outfile.txt
run75mtcopier1g_3:
	./mtcopier 75 data.1g outfile.txt
run75mtcopier1g_4:
	./mtcopier 75 data.1g outfile.txt
run75mtcopier1g_5:
	./mtcopier 75 data.1g outfile.txt

75mtcopier1g: run75mtcopier1g_1 run75mtcopier1g_2 run75mtcopier1g_3 run75mtcopier1g_4 run75mtcopier1g_5

run100mtcopier1g_1:
	./mtcopier 100 data.1g outfile.txt
run100mtcopier1g_2:
	./mtcopier 100 data.1g outfile.txt
run100mtcopier1g_3:
	./mtcopier 100 data.1g outfile.txt
run100mtcopier1g_4:
	./mtcopier 100 data.1g outfile.txt
run100mtcopier1g_5:
	./mtcopier 100 data.1g outfile.txt

100mtcopier1g: run100mtcopier1g_1 run100mtcopier1g_2 run100mtcopier1g_3 run100mtcopier1g_4 run100mtcopier1g_5

run25mtcopier2g_1:
	./mtcopier 25 data.2g outfile.txt
run25mtcopier2g_2:
	./mtcopier 25 data.2g outfile.txt
run25mtcopier2g_3:
	./mtcopier 25 data.2g outfile.txt
run25mtcopier2g_4:
	./mtcopier 25 data.2g outfile.txt
run25mtcopier2g_5:
	./mtcopier 25 data.2g outfile.txt

25mtcopier2g: run25mtcopier2g_1 run25mtcopier2g_2 run25mtcopier2g_3 run25mtcopier2g_4 run25mtcopier2g_5

run50mtcopier2g_1:
	./mtcopier 50 data.2g outfile.txt
run50mtcopier2g_2:
	./mtcopier 50 data.2g outfile.txt
run50mtcopier2g_3:
	./mtcopier 50 data.2g outfile.txt
run50mtcopier2g_4:
	./mtcopier 50 data.2g outfile.txt
run50mtcopier2g_5:
	./mtcopier 50 data.2g outfile.txt

50mtcopier2g: run50mtcopier2g_1 run50mtcopier2g_2 run50mtcopier2g_3 run50mtcopier2g_4 run50mtcopier2g_5

run75mtcopier2g_1:
	./mtcopier 75 data.2g outfile.txt
run75mtcopier2g_2:
	./mtcopier 75 data.2g outfile.txt
run75mtcopier2g_3:
	./mtcopier 75 data.2g outfile.txt
run75mtcopier2g_4:
	./mtcopier 75 data.2g outfile.txt
run75mtcopier2g_5:
	./mtcopier 75 data.2g outfile.txt

75mtcopier2g: run75mtcopier2g_1 run75mtcopier2g_2 run75mtcopier2g_3 run75mtcopier2g_4 run75mtcopier2g_5

run100mtcopier2g_1:
	./mtcopier 100 data.2g outfile.txt
run100mtcopier2g_2:
	./mtcopier 100 data.2g outfile.txt
run100mtcopier2g_3:
	./mtcopier 100 data.2g outfile.txt
run100mtcopier2g_4:
	./mtcopier 100 data.2g outfile.txt
run100mtcopier2g_5:
	./mtcopier 100 data.2g outfile.txt

100mtcopier2g: run100mtcopier2g_1 run100mtcopier2g_2 run100mtcopier2g_3 run100mtcopier2g_4 run100mtcopier2g_5

run25mtcopier4g_1:
	./mtcopier 25 data.4g outfile.txt
run25mtcopier4g_2:
	./mtcopier 25 data.4g outfile.txt
run25mtcopier4g_3:
	./mtcopier 25 data.4g outfile.txt
run25mtcopier4g_4:
	./mtcopier 25 data.4g outfile.txt
run25mtcopier4g_5:
	./mtcopier 25 data.4g outfile.txt

25mtcopier4g: run25mtcopier4g_1 run25mtcopier4g_2 run25mtcopier4g_3 run25mtcopier4g_4 run25mtcopier4g_5

run50mtcopier4g_1:
	./mtcopier 50 data.4g outfile.txt
run50mtcopier4g_2:
	./mtcopier 50 data.4g outfile.txt
run50mtcopier4g_3:
	./mtcopier 50 data.4g outfile.txt
run50mtcopier4g_4:
	./mtcopier 50 data.4g outfile.txt
run50mtcopier4g_5:
	./mtcopier 50 data.4g outfile.txt

50mtcopier4g: run50mtcopier4g_1 run50mtcopier4g_2 run50mtcopier4g_3 run50mtcopier4g_4 run50mtcopier4g_5

run75mtcopier4g_1:
	./mtcopier 75 data.4g outfile.txt
run75mtcopier4g_2:
	./mtcopier 75 data.4g outfile.txt
run75mtcopier4g_3:
	./mtcopier 75 data.4g outfile.txt
run75mtcopier4g_4:
	./mtcopier 75 data.4g outfile.txt
run75mtcopier4g_5:
	./mtcopier 75 data.4g outfile.txt

75mtcopier4g: run75mtcopier4g_1 run75mtcopier4g_2 run75mtcopier4g_3 run75mtcopier4g_4 run75mtcopier4g_5

run100mtcopier4g_1:
	./mtcopier 100 data.4g outfile.txt
run100mtcopier4g_2:
	./mtcopier 100 data.4g outfile.txt
run100mtcopier4g_3:
	./mtcopier 100 data.4g outfile.txt
run100mtcopier4g_4:
	./mtcopier 100 data.4g outfile.txt
run100mtcopier4g_5:
	./mtcopier 100 data.4g outfile.txt

100mtcopier4g: run100mtcopier4g_1 run100mtcopier4g_2 run100mtcopier4g_3 run100mtcopier4g_4 run100mtcopier4g_5

mtcopier512m: 25mtcopier512m 50mtcopier512m 75mtcopier512m 100mtcopier512m
mtcopier1g: 25mtcopier1g 50mtcopier1g 75mtcopier1g 100mtcopier1g
mtcopier2g: 25mtcopier2g 50mtcopier2g 75mtcopier2g 100mtcopier2g
mtcopier4g: 25mtcopier4g 50mtcopier4g 75mtcopier4g 100mtcopier4g

mtcopiertest: mtcopier512m mtcopier1g mtcopier2g mtcopier4g

runall: copiertest mtcopiertest