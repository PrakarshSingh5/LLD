package main

import (
	"fmt"
	"net/http"
	"time"
)

func main() {

	var cachedPrice string
	var cacheTime time.Time

	http.HandleFunc("/price", func(w http.ResponseWriter, r *http.Request) {
		// Simulate slow DB / computation

		if time.Since(cacheTime) < 10*time.Second {
			fmt.Fprintln(w, "Price is ", cachedPrice)
			return
		}
		time.Sleep(300 * time.Millisecond)
		cachedPrice = "Price is 100"
		cacheTime = time.Now()
		fmt.Fprintln(w, "Price is 100")
	})

	fmt.Println("Server running at http://localhost:8080")
	http.ListenAndServe(":8080", nil)
}
