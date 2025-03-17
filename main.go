package main

import (
	"fmt"
	"net/http"
)

func main() {
	fmt.Println("Init")
	setup_web_server()
}

func setup_web_server() {
	mux := http.NewServeMux()

	//Web Endpoints
	mux.Handle("/", http.FileServer(http.Dir("./static")))

	fmt.Printf("Starting server at port 3000\n")
	http.ListenAndServe(":3000", mux)
}
