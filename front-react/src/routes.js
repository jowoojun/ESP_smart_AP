import React, {PureComponent} from 'react';
import {Router, Route, browserHistory, IndexRoute} from 'react-router';

import {IndexNav, AdvanceNav} from './components';
import {NetworkInfoContainer} from './containers';
import {AdminInfoContainer} from './containers';
import {InternetConnectContainer} from './containers';



class routes extends PureComponent{

    render(){
        return(
            <Router history={browserHistory}>
                <Route path='/' component={IndexNav}>
                    <IndexRoute component={NetworkInfoContainer}/>
                    <Route path='admin' component={AdminInfoContainer} />
                </Route>
                <Route path='/advance' component={AdvanceNav}>
                    <IndexRoute component={InternetConnectContainer}/>
                    <Route path=''/>
                </Route>
            </Router>
        );
    }
}

export default routes;
