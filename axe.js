// This is the JS version that was written first, before being pasted into C++
// Can be pasted directly into the browser console
var input = 23;
var x, y, a, e, f, i, w, h, g, t = (input + 1) / 2;
w = Math.max(2 + 2 * (t), 4);
y = 0;
h =  10 + Math.max(0, t - 2) + Math.max(0, t - 9);
a = new Array(w);
for (i = 0; i < w * h; i ++) {
	  x = i % w;
	  e = Math.max(0, t - 2);
	  f = Math.floor(Math.abs(x - w / 2 + 0.5))
	  if ((e <= y && y <= e + 10 && (x == w / 2 || x == w / 2 - 1)) || (f >= 1 && Math.abs(e + 1 - y) <= f - 1))
	    a[x] = "▓";
	  else
	    a[x] = "░";
	  if (x == w - 1) {
	  	  
	    console.log( ": " + a.join("|"));
	    y++;
	  }
}
