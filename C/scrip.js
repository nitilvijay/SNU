document.getElementById('login-form').addEventListener('submit', function(event) {
    event.preventDefault();
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    // Perform login logic (e.g., submit to server)
    alert('Login attempt: ' + username);
});