from datetime import datetime

seconds = datetime.now().timestamp()

print("Seconds since January 1, 1970:", f"{seconds:,.4f}",
      "or", "{:.2e}".format(seconds), "in scientific notation")
print(datetime.fromtimestamp(seconds).strftime("%b %d %Y"))