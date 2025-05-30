# workspace.py - Sign-in client only
"""
Usage:
  python workspace.py --ip IP_ADDRESS --port PORT --name "First Last" [--message "Optional message"]
"""
import argparse
import json
import urllib.request
import urllib.error


def run_client(ip, port, student, message=''):
    url = f"http://{ip}:{port}/signin"
    payload = {
        'student': student,
        'message': message,
    }

    data = json.dumps(payload).encode()
    req = urllib.request.Request(
        url,
        data=data,
        headers={'Content-Type': 'application/json'}
    )
    try:
        with urllib.request.urlopen(req) as resp:
            res = json.loads(resp.read())
            status = res.get('status')
            session = res.get('session')
            print(f"Sign-in {status} ({session})")
    except urllib.error.HTTPError as e:
        print(f"HTTP Error {e.code}: {e.reason}")
    except Exception as e:
        print(f"Request failed: {e}")


def parse_args():
    parser = argparse.ArgumentParser(description='Sign-in client')
    parser.add_argument('-i', '--ip', required=True, help='Server IP or hostname')
    parser.add_argument('-p', '--port', default=1337, type=int, help='Server port')
    parser.add_argument('-n', '--name', default='FirstName LastName', help='Student name - check with instructor to match roster listing')
    parser.add_argument('-m', '--message', help='Optional message to include with sign-in')
    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()
    run_client(args.ip, args.port, args.name, args.message)
