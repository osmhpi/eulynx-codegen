import React from 'react';
import * as grpcWeb from 'grpc-web';
import './App.css';
import { SubsystemPointClient } from './proto/Subsystem_pointServiceClientPb';
import { Input, MovePointPosition, Nothing, State } from './proto/subsystem_point_pb';

interface AppState {
  client: SubsystemPointClient;
  stream: grpcWeb.ClientReadableStream<State> | null;
  connected: boolean;
  pointPosition: string | null;
}

class App extends React.Component<{}, AppState> {
  constructor(p: {}) {
    super(p);

    const url = window.location.protocol + '//' + window.location.host + (window.location.pathname.endsWith('/') ? window.location.pathname.slice(0, -1) : window.location.pathname);
    const client = new SubsystemPointClient(url);
    this.state = {
      connected: false,
      client,
      stream: null,
      pointPosition: null
    };
  }

  componentDidMount() {
    const stream = this.state.client.connectWeb(new Nothing());
    this.setState({
      stream
    })

    stream.on('data', response => {
      this.setState({
        pointPosition: response.getPointposition()
      })
    });
    stream.on('end', () => {
      // stream end signal
    });
  }

  componentWillUnmount() {
    if (this.state.stream) {
        this.state.stream.cancel();
        this.setState({
            stream: null,
        })
    }
  }

  render() {
    return (
      <div className="container">
        <p>Point Position and Degraded State: {this.state.pointPosition}</p>
        <div>
          <button onClick={() => this.commandLeft()}>Command Left</button>
          <button onClick={() => this.commandRight()}>Command Right</button>
        </div>
      </div>
    );
  }
  commandRight(): React.MouseEventHandler<HTMLButtonElement> | undefined {
    const input = new Input();
    input.setMovepoint(MovePointPosition.RIGHT);
    void this.state.client.movePoint(input, null);
    return;
  }

  commandLeft(): React.MouseEventHandler<HTMLButtonElement> | undefined {
    const input = new Input();
    input.setMovepoint(MovePointPosition.LEFT);
    void this.state.client.movePoint(input, null);
    return;
  }
}

export default App;
