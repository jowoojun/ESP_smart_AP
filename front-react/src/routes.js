import React, {PureComponent} from 'react';
import {Router, Route, browserHistory, IndexRoute} from 'react-router';

import {IndexNav, AdvanceNav} from './components';
import {NetworkInfoContainer} from './containers';
import {AdminInfoContainer} from './containers';
import {IPSettingContainer} from './containers';
import {SystemLogContainer} from './containers';

import {RefuseContainer} from './containers';

class routes extends PureComponent{

    render(){
        return(
            <Router history={browserHistory}>
                <Route path='/' component={IndexNav}>
                    <IndexRoute component={NetworkInfoContainer}/>
                    <Route path='admin' component={AdminInfoContainer} />
                    <Route path='ip' component={IPSettingContainer} />
                    <Route path='log' component={SystemLogContainer} />
                </Route>
                <Route path='/advance' component={AdvanceNav}>
                    <IndexRoute component={RefuseContainer}/>
                    <Route path='reservation' component={RefuseContainer}/>
                </Route>
            </Router>
        );
    }
}

export default routes;
