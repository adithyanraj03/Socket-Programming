# Socket Programming

The classic **daytime protocol** (RFC 867) implemented as TCP client/server
pairs in three languages: C, Python, and Java. A client opens a connection,
the server replies with the current local date and time as a single line, and
the connection is closed.

## Files

| File | Role | Language | Port |
|---|---|---|---|
| `day_server.c` / `day_client.c` | Daytime server / client | C (POSIX sockets) | entered interactively at run time |
| `day_server.py` / `day_client.py` | Daytime server / client | Python | `8999` |
| `daytimeserver.java` / `daytimeclient.java` | Daytime server / client | Java | `1397` |

## How to run

Run the server first, then the client (on the same machine).

### C (POSIX)

```sh
gcc day_server.c -o day_server
gcc day_client.c -o day_client

./day_server        # prompt: Enter the server port:
./day_client        # prompt: Enter the port
```

Both programs ask for the port at run time — use the same number in each.
The C server handles **one** client and then exits; the client connects,
prints the time it receives, and exits.

### Python

```sh
python day_server.py    # listens on port 8999, handles clients in a loop
python day_client.py    # connects to port 8999 and prints the reply
```

The Python server loops and serves one client at a time (closing each
connection after the reply).

### Java

```sh
javac daytimeserver.java daytimeclient.java
java daytimeserver             # listens on port 1397, loops
java daytimeclient [hostname]  # defaults to localhost
```

The Java client takes an optional hostname argument; it reads one line from
the server and prints `It is <time> at <host>`.

## Notes

- The C client connects to `INADDR_ANY` (`0.0.0.0`), so it is intended to be
  run on the same machine as the C server.
- The Python and Java servers run indefinitely; stop them with `Ctrl+C`.
- Response format is the platform's native date string (e.g.
  `Sat Jun 24 18:30:00 2023`), one line, terminated with `\r\n` where
  applicable.

## License

[MIT](LICENSE) © 2023 Adithya N Raj
