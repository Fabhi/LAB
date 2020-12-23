dir?="."
mk?="new"

.ONESHELL:
all: dir build run

dir:
	mkdir -p $(dir)/bin

build:
	cc $(dir)/client.c -o $(dir)/bin/c.out
	cc $(dir)/server.c -o $(dir)/bin/s.out

run:
	gnome-terminal --title="Server" --window -- $(dir)/bin/s.out
	gnome-terminal --title="Client" --window -- $(dir)/bin/c.out

create:
	mkdir -p $(mk)
	touch $(mk)/client.c
	touch $(mk)/server.c
