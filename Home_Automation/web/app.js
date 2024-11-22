function sendCommand(command) {
  fetch('http://<SERVER_IP>:5000/api/control', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ command }),
  }).then(response => console.log('Command sent:', command));
}
